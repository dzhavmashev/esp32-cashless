// Function : FUN_40142394
// Address  : 0x40142394
// Size     : 233 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40142394(undefined4 param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5,
                 byte *param_6)

{
  undefined4 uVar1;
  byte *pbVar2;
  byte *in_a12;
  byte *in_a14;
  byte *in_t0;
  undefined1 auStack_34 [16];
  byte *pbStack_24;
  
  memw();
  memw();
  pbStack_24 = _DAT_3ffc5708;
  pbVar2 = (byte *)((uint)param_3 & 0xf);
  uVar1 = 0xffffffda;
  if ((byte *)((uint)param_3 & 0xf) == (byte *)0x0) {
    in_a14 = param_5 + (int)param_3;
    pbVar2 = param_3;
    if (param_2 != (byte *)0x0) goto LAB_4014246c;
    param_3 = param_6 + (int)param_3;
    memw();
    for (; param_6 != param_3; param_6 = param_6 + 0x10) {
      (*(code *)&SUB_4008b3d0)(auStack_34,param_5,0x10);
      FUN_401421e8(param_1,0,param_5,param_6);
      *param_6 = *param_4 ^ *param_6;
      memw();
      in_a12 = &DAT_00000010;
      memw();
      (*(code *)&SUB_4008b3d0)(param_4,auStack_34);
      param_5 = param_5 + 0x10;
    }
    pbVar2 = param_6;
    uVar1 = 0;
  }
  while( true ) {
    param_6 = in_t0;
    param_1 = uVar1;
    param_3 = pbStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (pbStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
    in_t0 = param_6;
    do {
      *param_5 = *in_a12 ^ *param_4;
      memw();
      pbVar2 = pbVar2 + -0x10;
      memw();
      FUN_401421e8(param_1,param_2,param_5,param_5);
      (*(code *)&SUB_4008b3d0)(param_4,param_5,0x10);
LAB_4014246c:
      in_a12 = in_a14 + -(int)pbVar2;
      param_5 = param_6 + (int)param_3 + -(int)pbVar2;
    } while (pbVar2 != (byte *)0x0);
    uVar1 = 0;
  }
  return;
}

