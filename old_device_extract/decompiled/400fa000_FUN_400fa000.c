// Function : FUN_400fa000
// Address  : 0x400fa000
// Size     : 229 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400fa000(int param_1,undefined1 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uStack_48;
  undefined1 auStack_44 [28];
  char cStack_28;
  char cStack_27;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = 0x1101;
  if (*(int *)(param_1 + 100) == 1) {
    uStack_48 = 0;
    memw();
    iVar1 = FUN_400f9c84(param_1,param_2,0x48,param_3,&uStack_48,auStack_44,0xff,param_4);
    if ((iVar1 == 0) &&
       (iVar2 = FUN_400fbaa4(uStack_48,param_2,0x48,param_3,0xff,param_4), iVar1 = iVar2, iVar2 == 0
       )) {
      if ((param_4 == -1) || (param_4 == cStack_27)) {
        for (cVar3 = cStack_27; iVar1 = iVar2, (char)(cStack_27 + cStack_28) != cVar3;
            cVar3 = cVar3 + '\x01') {
          memw();
          iVar1 = FUN_400f9c84(param_1,param_2,0x42,param_3,&uStack_48,auStack_44,cVar3,0xff);
          if (((iVar1 != 0) && (iVar1 != 0x1102)) ||
             ((iVar1 != 0x1102 &&
              (iVar1 = FUN_400fbaa4(uStack_48,param_2,0x42,param_3,cVar3,0xff), iVar1 != 0))))
          break;
        }
      }
      else {
        iVar1 = -1;
      }
    }
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

