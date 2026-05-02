// Function : FUN_4018cca4
// Address  : 0x4018cca4
// Size     : 229 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018cca4(undefined4 param_1)

{
  uint *puVar1;
  short sVar2;
  uint *puVar3;
  uint *puVar4;
  
  memw();
  puVar1 = (uint *)FUN_4018ce90();
  puVar3 = _DAT_3ffc06fc;
  if (DAT_3ffc7ddc == 0) {
    if (puVar1 == (uint *)0x0) {
      memw();
      FUN_40147fe4(6,0x800,1," %s %u\n","duSched","xBlocks",0x67d);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else if (puVar1 != (uint *)0x0) {
    DAT_3ffc7ddc = 0;
    memw();
    memw();
  }
  (**(code **)(_DAT_3ffc1a34 + 0x28))(_DAT_3ffc1a38);
  sVar2 = 0;
  while (puVar3 != (uint *)0x0) {
    puVar4 = (uint *)puVar3[2];
    sVar2 = sVar2 + 1;
    memw();
    if ((*puVar3 & 0x40000000) != 0) {
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0x2c))(_DAT_3ffc1a38);
      FUN_4018c9f0(puVar3,sVar2,param_1);
      (**(code **)(_DAT_3ffc1a34 + 0x28))(_DAT_3ffc1a38);
      sVar2 = 0;
    }
    if (puVar3 == puVar1) break;
    memw();
    puVar1 = (uint *)FUN_4018ce90();
    puVar3 = puVar4;
    if (DAT_3ffc7ddc < (puVar1 == (uint *)0x0)) {
      memw();
      FUN_40147fe4(6,0x800,1,"mber=%d","duSched","xBlocks",0x696);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  (**(code **)(_DAT_3ffc1a34 + 0x2c))(_DAT_3ffc1a38);
  return;
}

