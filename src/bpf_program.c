#include <asm/ptrace.h>
#include <linux/bpf.h>

#define SEC(NAME) __attribute__((section(NAME), used))

static int (*bpf_trace_printk)(const char *fmt, int fmt_size,
                               ...) = (void *)BPF_FUNC_trace_printk;

struct blk_mq_queue_data {
	struct request *rq;
};

struct bio {
        unsigned short bi_vcnt;
	struct bio *bi_next;
	struct bio_vec *bi_io_vec;
};

struct request {
	struct bio *bio;
	struct bio *biotail;
};

SEC("kprobe/nvme_queue_rq")
int bpf_prog(struct pt_regs *ctx) {
  struct blk_mq_hw_ctx *hctx = (void *) ctx->rdi;
  struct blk_mq_queue_data *bd = (void *) ctx->rsi;

  struct request *req = bd->rq;
  struct bio *bio = req->bio;

  char msg[64];
  sprintf(msg, "Vectors: %u", bio->bi_vcnt);

  bpf_trace_printk(msg, sizeof(msg));
  return 0;
}

char _license[] SEC("license") = "GPL";
