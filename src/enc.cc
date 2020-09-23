#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>

#include "bcc_version.h"
#include "BPF.h"

const std::string BPF_PROGRAM = R"(

	//

)";

int main() {
  ebpf::BPF bpf;
  auto init_res = bpf.init(BPF_PROGRAM);

  if (init_res.code() != 0) {
    std::cerr << init_res.msg() << std::endl;
    return 1;
  }

  return 0;
}
