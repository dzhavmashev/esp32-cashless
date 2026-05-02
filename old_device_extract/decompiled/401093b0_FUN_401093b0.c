// Function : FUN_401093b0
// Address  : 0x401093b0
// Size     : 364 bytes


uint FUN_401093b0(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,uint param_5
                 ,int param_6)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined2 uStack_46;
  int aiStack_44 [3];
  int iStack_38;
  int iStack_34;
  int iStack_30;
  char cStack_2c;
  char cStack_28;
  undefined2 uStack_24;
  
  memw();
  puVar2 = (undefined4 *)FUN_40108224(param_1);
  if (puVar2 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  if ((*(uint *)*puVar2 & 0xf0) == 0x10) {
    FUN_40108194(puVar2);
    uVar3 = FUN_40109524(param_1,param_2,param_3,param_4);
    return uVar3;
  }
  if (param_3 < 0x10000) {
    if ((param_5 == 0 && param_6 == 0) ||
       ((((param_6 == 0x10 || param_6 == 0x1c && (param_5 != 0)) &&
         ((*(byte *)(param_5 + 1) & 0xf7) == 2)) && ((param_5 & 3) == 0)))) {
      aiStack_44[1] = 0;
      aiStack_44[0] = 0;
      if (param_5 == 0) {
        uStack_46 = 0;
        memw();
        aiStack_44[2] = 0;
        iStack_38 = aiStack_44[2];
        iStack_34 = aiStack_44[2];
        iStack_30 = aiStack_44[2];
        if ((*(uint *)*puVar2 & 8) == 0) {
          cStack_2c = '\0';
          memw();
          memw();
          cStack_28 = '\0';
        }
        else {
          cStack_28 = '\x06';
          memw();
          memw();
          cStack_2c = '\0';
        }
      }
      else {
        memw();
        FUN_40107e98(param_5,aiStack_44 + 2,&uStack_46);
      }
      uStack_24 = uStack_46;
      memw();
      memw();
      iVar5 = FUN_4011da28(aiStack_44,param_3);
      cVar1 = -1;
      if (iVar5 != 0) {
        (*(code *)&SUB_4008b3d0)(*(undefined4 *)(aiStack_44[0] + 4),param_2,param_3);
        if (((cStack_28 == '\x06') && (aiStack_44[2] == 0 && iStack_38 == 0)) &&
           (iStack_34 == -0x10000)) {
          cStack_28 = '\0';
          memw();
          aiStack_44[2] = iStack_30;
        }
        memw();
        cVar1 = FUN_4011c240(*puVar2,aiStack_44);
      }
      FUN_4011da74(aiStack_44);
      iVar5 = FUN_4011d9e4((int)cVar1);
      if (iVar5 != 0) {
        piVar4 = (int *)FUN_40173a8c();
        *piVar4 = iVar5;
      }
      memw();
      FUN_40108194(puVar2);
      if (cVar1 != '\0') {
        return 0xffffffff;
      }
      return param_3;
    }
    iVar5 = FUN_4011d9e4(0xfffffff0);
    if (iVar5 == 0) goto LAB_401093fe;
    piVar4 = (int *)FUN_40173a8c();
  }
  else {
    piVar4 = (int *)FUN_40173a8c();
    iVar5 = 0x7a;
  }
  *piVar4 = iVar5;
LAB_401093fe:
  memw();
  FUN_40108194(puVar2);
  return 0xffffffff;
}

