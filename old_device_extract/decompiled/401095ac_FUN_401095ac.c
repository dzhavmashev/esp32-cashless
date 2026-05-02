// Function : FUN_401095ac
// Address  : 0x401095ac
// Size     : 163 bytes


int FUN_401095ac(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_2 == 2) {
    uVar4 = 0x21;
    uVar5 = 0x20;
    if (param_1 != 2) {
      uVar4 = 0x29;
      uVar5 = 0x28;
    }
    if (param_3 == 0x88) {
      uVar5 = uVar4;
    }
    param_3 = 0;
LAB_401095f5:
    iVar1 = FUN_4011c040(uVar5,param_3,0x40107bf4);
    if (iVar1 != 0) {
      iVar3 = FUN_40107f74(iVar1,0);
      if (iVar3 == -1) {
        FUN_4011c0dc(iVar1);
        puVar2 = (undefined4 *)FUN_40173a8c();
        *puVar2 = 0x17;
        memw();
      }
      else {
        *(int *)(iVar1 + 0x20) = iVar3;
        memw();
        FUN_40108194(&DAT_3ffc58c8 + (iVar3 + -0x30) * 0x18);
      }
      goto LAB_40109614;
    }
    puVar2 = (undefined4 *)FUN_40173a8c();
    uVar5 = 0x69;
  }
  else {
    if (param_2 == 3) {
      param_3 = param_3 & 0xff;
      uVar5 = 0x40;
      uVar4 = 0x48;
LAB_401095d5:
      if (param_1 != 2) {
        uVar5 = uVar4;
      }
      goto LAB_401095f5;
    }
    if (param_2 == 1) {
      param_3 = 0;
      uVar5 = 0x10;
      uVar4 = 0x18;
      goto LAB_401095d5;
    }
    puVar2 = (undefined4 *)FUN_40173a8c();
    uVar5 = 0x16;
  }
  *puVar2 = uVar5;
  iVar3 = -1;
LAB_40109614:
  memw();
  return iVar3;
}

