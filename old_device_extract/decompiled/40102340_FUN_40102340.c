// Function : FUN_40102340
// Address  : 0x40102340
// Size     : 236 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40102340(byte *param_1,undefined4 param_2,byte *param_3,byte *param_4,byte *param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  uint in_t0;
  undefined8 uVar7;
  byte local_124 [256];
  byte *pbStack_24;
  
  puVar5 = (undefined4 *)&DAT_3ffc5708;
  memw();
  memw();
  pbStack_24 = _DAT_3ffc5708;
  local_124[0] = 0;
  memw();
  pbVar6 = (byte *)0x100;
  local_124[0] = local_124[*param_1];
  local_124[*param_1] = 0;
  memw();
  pbVar4 = (byte *)0x0;
  uVar3 = 0;
  uVar2 = 0;
  do {
    uVar7 = CONCAT44(puVar5,pbVar4);
    if (pbVar4 == param_3) {
      param_5 = param_4 + (int)param_5;
      while (param_3 = pbStack_24, param_5 != param_4) {
        uVar2 = uVar2 + 1 & 0xff;
        pbVar4 = local_124 + uVar2;
        bVar1 = *pbVar4;
        uVar3 = bVar1 + uVar3 & 0xff;
        *pbVar4 = local_124[uVar3];
        local_124[uVar3] = bVar1;
        memw();
        pbVar4 = local_124 + ((uint)bVar1 + (uint)*pbVar4 & 0xff);
        *param_4 = *pbVar4 ^ *param_4;
        memw();
        param_4 = param_4 + 1;
        memw();
      }
      memw();
      memw();
      if (pbStack_24 == (byte *)*puVar5) {
        return 0;
      }
      memw();
      uVar2 = in_t0;
      uVar7 = (*(code *)&SUB_40082ec4)(pbVar4,puVar5,pbVar6);
      uVar3 = uVar2;
      in_t0 = uVar2;
    }
    puVar5 = (undefined4 *)((ulonglong)uVar7 >> 0x20);
    uVar2 = uVar2 + 1 & 0xff;
    pbVar6 = local_124 + uVar2;
    bVar1 = *pbVar6;
    pbVar4 = (byte *)((int)uVar7 + 1);
    uVar3 = bVar1 + uVar3 & 0xff;
    *pbVar6 = local_124[uVar3];
    local_124[uVar3] = bVar1;
    memw();
    memw();
  } while( true );
}

