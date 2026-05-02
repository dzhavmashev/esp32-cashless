// Function : FUN_40106090
// Address  : 0x40106090
// Size     : 134 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_40106090(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 auStack_54 [48];
  int iStack_24;
  
  uVar4 = CONCAT44(param_2,param_1);
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (param_4 == 1) {
    uVar3 = param_5;
    uVar1 = FUN_40102124(param_1,param_2,param_5,param_6,param_7);
    goto LAB_401060b4;
  }
  uVar3 = param_6;
  if (1 < param_4) goto LAB_401060cc;
  if ((param_4 == 0) && (param_3 == 0x400)) goto LAB_401060d2;
LAB_401060b2:
  do {
    uVar1 = 0xffffffff;
LAB_401060b4:
    while( true ) {
      while( true ) {
        param_4 = iStack_24;
        param_7 = _DAT_3ffc5708;
        memw();
        memw();
        if (iStack_24 == _DAT_3ffc5708) {
          return uVar1;
        }
        memw();
        uVar4 = (*(code *)&SUB_40082ec4)();
LAB_401060cc:
        param_1 = (undefined4)uVar4;
        if (param_4 == 2) break;
        if (param_4 != 3) goto LAB_401060b2;
LAB_401060d2:
        uVar1 = FUN_401025f4(param_1,param_5);
      }
      uVar1 = param_5;
      iVar2 = FUN_40102164(param_1,(int)((ulonglong)uVar4 >> 0x20),param_5,uVar3,auStack_54);
      uVar3 = uVar1;
      if (iVar2 != 0) break;
      uVar3 = 0x10;
      (*(code *)&SUB_4008b3d0)(param_7,auStack_54);
      uVar1 = 0;
    }
  } while( true );
}

