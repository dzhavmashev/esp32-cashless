// Function : FUN_400f0798
// Address  : 0x400f0798
// Size     : 100 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f0798(undefined4 param_1,uint param_2,uint param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  char cStack_25;
  uint uStack_24;
  
  param_3 = param_3 & 0xff;
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  cStack_25 = '\0';
  if (param_3 < 2) {
    param_3 = 10;
  }
  pcVar5 = &cStack_25;
  uVar7 = 9;
  while( true ) {
    do {
      cVar3 = (char)(param_2 % param_3);
      cVar2 = cVar3 + '7';
      uVar6 = param_2 / param_3;
      if (param_2 % param_3 <= uVar7) {
        cVar2 = cVar3 + '0';
      }
      pcVar5 = pcVar5 + -1;
      *pcVar5 = cVar2;
      bVar1 = param_3 <= param_2;
      param_2 = uVar6;
    } while (bVar1);
    uVar4 = FUN_400f0684(param_1);
    param_3 = uStack_24;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) break;
    param_2 = uVar6;
    uVar8 = func_0x40082ecc();
    pcVar5 = (char *)((ulonglong)uVar8 >> 0x20);
    param_1 = (undefined4)uVar8;
  }
  return uVar4;
}

