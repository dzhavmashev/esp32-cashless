// Function : FUN_400e7250
// Address  : 0x400e7250
// Size     : 28 bytes


void FUN_400e7250(int param_1,char param_2)

{
  char *pcVar1;
  
  *(char *)(param_1 + 0xc) = param_2;
  pcVar1 = "feedbackEnabled";
  if (param_2 == '\0') {
    pcVar1 = "ialized";
  }
  FUN_400f06a4(0x3ffc5490,"isabled",pcVar1);
  return;
}

