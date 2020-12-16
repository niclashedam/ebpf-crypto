#include <asm/ptrace.h>
#include <linux/bpf.h>
#include "bpf_helpers.h"
#include "bio.h"

SEC("kprobe/nvme_queue_rq")
int bpf_prog(struct pt_regs *ctx) {
  struct blk_mq_queue_data bd;
  struct request req;
  struct bio bio;

  bpf_probe_read(&bd, sizeof(bd), (void *) ctx->rsi);
  bpf_probe_read(&req, sizeof(req), bd.rq);
  bpf_probe_read(&bio, sizeof(bio), req.bio);

  char fmt[] = "This request has %u vectors\n";
  bpf_trace_printk(fmt, sizeof(fmt), bio.bi_vcnt, sizeof(bio.bi_vcnt));

  return 0;
}

char _license[] SEC("license") = "GPL";
