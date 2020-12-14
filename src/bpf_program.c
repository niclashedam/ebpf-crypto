#include <asm/ptrace.h>
#include <linux/bpf.h>
#include <linux/bio.h>


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
