#include <asm/ptrace.h>
#include <linux/bpf.h>
#include "bpf_helpers.h"
#include "bio.h"

SEC("kprobe/nvme_queue_rq")
int bpf_prog(struct pt_regs *ctx) {
  struct blk_mq_queue_data *bd = (void *) ctx->rsi;

  struct request *req = bd->rq;
  struct bio *bio = req->bio;

  char fmt[] = "This request has %u vectors\n";
  bpf_trace_printk(fmt, sizeof(fmt), bio->bi_vcnt, sizeof(unsigned short));

  return 0;
}

char _license[] SEC("license") = "GPL";
