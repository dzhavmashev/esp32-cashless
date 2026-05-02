// Function : FUN_4010b1a0
// Address  : 0x4010b1a0
// Size     : 75 bytes


void FUN_4010b1a0(int param_1,uint param_2)

{
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("d netif",0x388,"_output","d netif");
  }
  if ((*(byte *)(param_1 + 0xeb) & 5) == 5) {
    if (((param_2 & 1) != 0) && (*(int *)(param_1 + 4) != 0)) {
      if ((*(byte *)(param_1 + 0xeb) & 8) != 0) {
        FUN_40115ac4(param_1,param_1 + 4);
      }
      if ((*(byte *)(param_1 + 0xeb) & 0x20) != 0) {
        FUN_401162f0(param_1);
      }
    }
    if ((param_2 & 2) != 0) {
      FUN_40118534(param_1);
    }
  }
  return;
}

