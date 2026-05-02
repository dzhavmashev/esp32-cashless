// Function : FUN_40106150
// Address  : 0x40106150
// Size     : 124 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40106150(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 auStack_4d [9];
  undefined1 auStack_44 [32];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_5c = 0x68735f32;
  uStack_54 = 8;
  uStack_58 = 0x3161;
  memw();
  uStack_68 = (*(code *)&SUB_4008b3d0)(auStack_4d,&DAT_3f40f1e4,9);
  uStack_64 = param_3;
  uStack_60 = param_4;
  if (param_6 == 0) goto LAB_401061c4;
  memw();
  FUN_401020e4(param_1,param_2,3,&uStack_68,&uStack_5c,auStack_44);
  while( true ) {
    (*(code *)&SUB_4008b3d0)(param_5,auStack_44,0x10);
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
LAB_401061c4:
    FUN_40102144();
  }
  return;
}

