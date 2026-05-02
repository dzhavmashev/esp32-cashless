// Function : FUN_4013937c
// Address  : 0x4013937c
// Size     : 116 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4013937c(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_64 [64];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar3 = -0x5100;
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) && (iVar2 = param_1[2], iVar2 != 0)) {
    bVar1 = *(byte *)(*param_1 + 9);
    memw();
    iVar3 = FUN_401391c4(param_1,auStack_64);
    if (((iVar3 == 0) && (iVar3 = FUN_40139114(param_1), iVar3 == 0)) &&
       ((iVar3 = FUN_40139174(param_1,iVar2 + (uint)bVar1,*(undefined1 *)(*param_1 + 9)), iVar3 == 0
        && (iVar3 = FUN_40139174(param_1,auStack_64,*(undefined1 *)(*param_1 + 8)), iVar3 == 0)))) {
      iVar3 = FUN_401391c4(param_1,param_2);
    }
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar3;
}

