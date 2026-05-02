// Function : FUN_4012ca14
// Address  : 0x4012ca14
// Size     : 126 bytes


void FUN_4012ca14(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x44);
  if (iVar1 != 0) {
    FUN_401416e8(iVar1 + 0x26c);
    FUN_4013ec50(iVar1 + 0x2c4);
    FUN_4013f798(iVar1 + 0x324);
    FUN_401409a0(iVar1 + 0x398);
    FUN_401344a4(iVar1 + 0x28);
    FUN_40134584(iVar1 + 0xa4);
    FUN_4013ae44(*(undefined4 *)(iVar1 + 0x1d8));
    if (*(int *)(iVar1 + 0x1dc) != 0) {
      FUN_4013ae54(*(int *)(iVar1 + 0x1dc),*(undefined4 *)(iVar1 + 0x1e0));
      FUN_4013ae44(*(undefined4 *)(iVar1 + 0x1dc));
    }
    iVar2 = *(int *)(iVar1 + 0x1e8);
    while (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 8);
      FUN_4013ae44();
    }
    FUN_4013ae44(*(undefined4 *)(iVar1 + 0x240));
    FUN_4012998c(*(undefined4 *)(iVar1 + 0x24c));
    FUN_40129da0(param_1);
    FUN_4013ae54(iVar1,0x8d8);
  }
  return;
}

