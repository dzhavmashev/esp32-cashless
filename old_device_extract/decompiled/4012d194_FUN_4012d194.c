// Function : FUN_4012d194
// Address  : 0x4012d194
// Size     : 114 bytes


undefined4 FUN_4012d194(undefined4 param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  uVar3 = 0x80;
  if (param_3 == 1) {
    uVar2 = *(uint *)(param_2 + 0x10);
    if (uVar2 < 5) {
      if ((uVar2 < 2) && (uVar3 = 0x20, uVar2 != 1)) {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0x20;
      if (((uVar2 != 7) && (uVar3 = 0, 6 < uVar2)) && (uVar2 - 9 < 2)) {
        uVar3 = 8;
      }
    }
  }
  iVar1 = FUN_40144164(param_1,uVar3);
  uVar3 = 0;
  if (iVar1 != 0) {
    *param_4 = *param_4 | 0x800;
    uVar3 = 0xffffffff;
  }
  puVar4 = &DAT_3f41ab9c;
  if (param_3 != 1) {
    puVar4 = &DAT_3f41aba5;
  }
  memw();
  iVar1 = FUN_4014419c(param_1,puVar4,8);
  if (iVar1 != 0) {
    *param_4 = *param_4 | 0x1000;
    uVar3 = 0xffffffff;
  }
  memw();
  return uVar3;
}

