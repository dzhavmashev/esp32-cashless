// Function : FUN_400ed9cc
// Address  : 0x400ed9cc
// Size     : 33 bytes


void FUN_400ed9cc(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  if ((*(byte *)(param_2 + 0xf) & 0x80) == 0) {
    uVar1 = *(uint *)(param_2 + 8);
  }
  else {
    uVar1 = *(uint *)(param_2 + 0xc) >> 0x18 & 0x7f;
  }
  FUN_400f1520(param_1,param_2,param_3,uVar1);
  return;
}

