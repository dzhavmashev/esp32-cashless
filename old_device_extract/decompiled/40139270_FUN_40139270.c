// Function : FUN_40139270
// Address  : 0x40139270
// Size     : 232 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40139270(int *param_1,undefined1 *param_2,undefined1 *param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  undefined1 *puVar1;
  int *piVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 auStack_64 [64];
  undefined1 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  piVar2 = (int *)0xffffaf00;
  if (param_1 == (int *)0x0) goto LAB_40139311;
  if (*param_1 == 0) goto LAB_40139311;
  param_6 = param_1[2];
  if (param_6 == 0) goto LAB_40139311;
  if ((undefined1 *)(uint)*(byte *)(*param_1 + 9) < param_3) {
    memw();
    piVar2 = (int *)FUN_40139114(param_1);
    if (piVar2 != (int *)0x0) goto LAB_4013930a;
    piVar2 = (int *)FUN_40139174(param_1,param_2,param_3);
    if (piVar2 != (int *)0x0) goto LAB_4013930a;
    piVar2 = (int *)FUN_401391c4(param_1,auStack_64);
    if (piVar2 != (int *)0x0) goto LAB_4013930a;
    param_3 = (undefined1 *)(uint)*(byte *)(*param_1 + 8);
    param_2 = auStack_64;
  }
  param_6 = param_1[2];
  puVar1 = (undefined1 *)(param_6 + (uint)*(byte *)(*param_1 + 9));
  (*(code *)&SUB_4008b530)(param_6,0x36);
  (*(code *)&SUB_4008b530)(puVar1,0x5c,*(undefined1 *)(*param_1 + 9));
  puVar3 = (undefined1 *)0x0;
  do {
    if (param_3 == puVar3) {
      piVar2 = (int *)FUN_40139114(param_1);
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)FUN_40139174(param_1,param_6,*(undefined1 *)(*param_1 + 9));
      }
LAB_4013930a:
      FUN_4013ae54(auStack_64,0x40);
LAB_40139311:
      param_1 = piVar2;
      puVar1 = puStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (puStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      puVar3 = &DAT_3ffc5708;
    }
    pbVar5 = param_2 + (int)puVar3;
    puVar3[param_6] = puVar3[param_6] ^ *pbVar5;
    memw();
    pbVar4 = puVar1 + (int)puVar3;
    puVar3 = puVar3 + 1;
    *pbVar4 = *pbVar4 ^ *pbVar5;
    memw();
    memw();
  } while( true );
}

