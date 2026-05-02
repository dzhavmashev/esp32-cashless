// Function : FUN_400ede04
// Address  : 0x400ede04
// Size     : 24 bytes


undefined4 FUN_400ede04(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&LAB_40184637_1)(param_1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  return uVar2;
}

