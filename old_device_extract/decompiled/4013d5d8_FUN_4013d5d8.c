// Function : FUN_4013d5d8
// Address  : 0x4013d5d8
// Size     : 309 bytes


int FUN_4013d5d8(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  
  iVar1 = FUN_40131798(param_2);
  iVar2 = FUN_40131798(param_3);
  uVar9 = iVar2 + 0x1fU >> 5;
  uVar6 = iVar1 + 0x1fU >> 5;
  memw();
  iVar3 = FUN_40186728((uVar9 < uVar6) * uVar6 + (uVar9 >= uVar6) * uVar9);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    FUN_40131700(param_1,0);
    iVar1 = 0;
  }
  else if (iVar1 == 1) {
    iVar1 = FUN_4013167c(param_1,param_3);
    *param_1 = *param_1 * *param_2;
    memw();
  }
  else {
    if (iVar2 == 1) {
      iVar1 = FUN_4013167c(param_1,param_2);
      iVar2 = *param_1;
    }
    else {
      uVar5 = iVar1 + iVar2 + 0x1f;
      uVar7 = uVar5 >> 5;
      memw();
      iVar1 = FUN_40131574(param_1,uVar7);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (0x800 < (uint)(iVar3 << 5)) {
        if ((uVar5 & 0xffffffe0) < 0x1001) {
          uVar4 = FUN_40186728(uVar7);
          FUN_4013d7fc();
          FUN_4013d950(param_2,param_3,uVar4);
          iVar1 = FUN_40131574(param_1,uVar4);
          if (iVar1 == 0) {
            FUN_4013d864(param_1,uVar4);
            *param_1 = *param_2 * *param_3;
          }
          memw();
          FUN_4013d838();
          return iVar1;
        }
        piVar8 = param_2;
        if (uVar9 <= uVar6) {
          piVar8 = param_3;
          param_3 = param_2;
          uVar9 = uVar6;
        }
        iVar1 = FUN_4013d714(param_1,piVar8,param_3,uVar9);
        return iVar1;
      }
      memw();
      FUN_4013d7fc();
      FUN_4013d878(param_2,param_3,iVar3);
      FUN_4013d864(param_1,uVar7);
      FUN_4013d838();
      iVar2 = *param_2;
      iVar1 = 0;
    }
    *param_1 = iVar2 * *param_3;
    memw();
  }
  return iVar1;
}

