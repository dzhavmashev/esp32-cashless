// Function : FUN_40105924
// Address  : 0x40105924
// Size     : 226 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40105924(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                 undefined4 param_6,undefined4 param_7)

{
  byte bVar1;
  byte bStack_54;
  undefined1 auStack_53 [13];
  undefined1 uStack_46;
  undefined1 uStack_45;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 auStack_42 [14];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  bVar1 = 0x40;
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (param_5 == 0) {
    bVar1 = 0;
  }
  bStack_54 = bVar1 | (byte)((param_2 - 2U >> 1) << 3) | 1;
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(auStack_53,param_3,0xd);
  uStack_46 = (undefined1)((uint)param_6 >> 8);
  uStack_45 = (undefined1)param_6;
  memw();
  memw();
  FUN_401021b8(param_1,&bStack_54,param_7);
  if (param_5 != 0) {
    uStack_44 = (undefined1)(param_5 >> 8);
    uStack_43 = (undefined1)param_5;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_42,param_4,param_5);
    (*(code *)&SUB_4008b530)(auStack_42 + param_5,0,0x1e - param_5);
    FUN_401850c4(&uStack_44,param_7);
    FUN_401021b8(param_1,&uStack_44,param_7);
    if (0xe < param_5) {
      FUN_401850c4(auStack_34,param_7);
      FUN_401021b8(param_1,auStack_34,param_7);
    }
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return;
}

