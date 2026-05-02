// Function : FUN_400fe3dc
// Address  : 0x400fe3dc
// Size     : 92 bytes


void FUN_400fe3dc(undefined4 *param_1,int param_2,uint param_3,uint *param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint *puVar3;
  undefined1 *puVar4;
  
  puVar4 = (undefined1 *)*param_1;
  memw();
  memw();
  memw();
  uVar2 = 0x80 - (*(uint *)(puVar4 + 0x1c) >> 0x10 & 0xff);
  if ((uVar2 & 0xffff) <= param_3) {
    param_3 = uVar2;
  }
  *param_4 = param_3 & 0xffff;
  puVar3 = (uint *)&DAT_60000000;
  if ((puVar4 != &DAT_3ff40000) && (puVar3 = (uint *)&DAT_60010000, puVar4 != &DAT_3ff50000)) {
    puVar3 = (uint *)&DAT_6002e000;
  }
  uVar2 = 0;
  while (uVar2 < (param_3 & 0xffff)) {
    pbVar1 = (byte *)(param_2 + uVar2);
    uVar2 = uVar2 + 1;
    memw();
    *puVar3 = (uint)*pbVar1;
    memw();
  }
  memw();
  return;
}

