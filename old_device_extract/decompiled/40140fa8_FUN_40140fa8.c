// Function : FUN_40140fa8
// Address  : 0x40140fa8
// Size     : 185 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40140fa8(int param_1,int param_2,undefined1 *param_3,byte *param_4)

{
  byte *pbVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  byte local_34 [16];
  int iStack_24;
  
  memw();
  pbVar1 = param_3 + param_2;
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_4008b530)(local_34,0,0x10);
  puVar2 = param_3;
  do {
    pbVar3 = pbVar1 + -(int)puVar2;
    if (puVar2 < (undefined1 *)0x10) {
      pbVar3 = (byte *)0x0;
      if (param_3 + ((uint)param_3 >> 4) * -0x10 != (undefined1 *)0x0) {
        (*(code *)&SUB_4008b3d0)(local_34,param_2 + ((uint)param_3 >> 4) * 0x10);
        pbVar1 = local_34;
        puVar2 = (undefined1 *)(uint)(local_34[0] ^ *param_4);
        *param_4 = local_34[0] ^ *param_4;
        memw();
        memw();
        pbVar3 = param_4;
        FUN_40140e74(param_1,param_4);
      }
      param_2 = iStack_24;
      param_1 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      param_3 = &DAT_3ffc5708;
    }
    *param_4 = *pbVar3 ^ *param_4;
    memw();
    memw();
    FUN_40140e74(param_1,param_4,param_4);
    puVar2 = puVar2 + -0x10;
  } while( true );
}

