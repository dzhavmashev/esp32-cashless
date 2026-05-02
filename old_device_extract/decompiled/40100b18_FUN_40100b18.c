// Function : FUN_40100b18
// Address  : 0x40100b18
// Size     : 30 bytes


void FUN_40100b18(int param_1)

{
  if ((*(byte *)(param_1 + 0xeb) & 1) != 0) {
    FUN_40118534(param_1);
    FUN_40113258(40000,0x40100b10,param_1);
  }
  return;
}

