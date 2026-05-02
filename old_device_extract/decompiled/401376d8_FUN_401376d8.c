// Function : FUN_401376d8
// Address  : 0x401376d8
// Size     : 254 bytes


int FUN_401376d8(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uStack_64;
  int iStack_60;
  undefined1 *puStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [76];
  
  iVar1 = 0;
  if (param_3 <= *(uint *)(param_1 + 4)) {
    uVar2 = *(uint *)(param_1 + 4) - param_3;
    iStack_60 = (uVar2 < param_3) * uVar2 + (uVar2 >= param_3) * param_3;
    iStack_54 = 2;
    uStack_58 = 1;
    uStack_64 = 1;
    memw();
    puStack_5c = auStack_4c;
    uStack_50 = param_2;
    (*(code *)&SUB_4008b530)(auStack_4c,0,0x2c);
    iVar3 = *(int *)(param_1 + 8);
    iVar1 = iStack_60 + 2;
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_4c,iVar3 + param_3 * 4,iStack_60 << 2);
    uVar2 = param_3;
    while (uVar2 < *(uint *)(param_1 + 4)) {
      *(undefined4 *)(iVar3 + uVar2 * 4) = 0;
      uVar2 = uVar2 + 1;
      memw();
    }
    memw();
    iStack_60 = iVar1;
    iVar1 = FUN_4013d5d8(&uStack_64,&uStack_64,&uStack_58);
    if ((iVar1 == 0) && (iVar1 = FUN_40131b00(param_1,param_1,&uStack_64), iVar1 == 0)) {
      uVar2 = *(int *)(param_1 + 4) - param_3;
      iStack_60 = (uVar2 < param_3) * uVar2 + (uVar2 >= param_3) * param_3;
      memw();
      (*(code *)&SUB_4008b530)(auStack_4c,0,0x2c);
      iVar1 = iStack_60;
      iVar3 = *(int *)(param_1 + 8);
      memw();
      (*(code *)&SUB_4008b3d0)(auStack_4c,iVar3 + param_3 * 4,iStack_60 << 2);
      iStack_60 = iStack_54 + iVar1;
      while (param_3 < *(uint *)(param_1 + 4)) {
        *(undefined4 *)(iVar3 + param_3 * 4) = 0;
        param_3 = param_3 + 1;
        memw();
      }
      memw();
      iVar1 = FUN_4013d5d8(&uStack_64,&uStack_64,&uStack_58);
      if (iVar1 == 0) {
        iVar1 = FUN_40131b00(param_1,param_1,&uStack_64);
      }
    }
  }
  return iVar1;
}

