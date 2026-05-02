// Function : FUN_4018c68c
// Address  : 0x4018c68c
// Size     : 201 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018c68c(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  
  puVar3 = param_1;
  if (param_1 == (uint *)0x0) {
    memw();
    FUN_40147fe4(6,0x800,1,": %08x\n","duSched","irtyBuf",0x8ec);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  do {
    memw();
    memw();
    *puVar3 = *puVar3 | 0x80000000;
    memw();
    memw();
    *puVar3 = *puVar3 & 0xbfffffff;
    memw();
    memw();
    *puVar3 = *puVar3 & 0xdfffffff;
    memw();
    memw();
    memw();
    *puVar3 = *puVar3 & 0xff000fff | (*puVar3 & 0xfff) << 0xc;
    puVar4 = (undefined4 *)puVar3[1];
    *puVar4 = 0xdeadbeef;
    memw();
    *(undefined4 *)((int)puVar4 + (*puVar3 & 0xfff)) = 0xdeadbeef;
    puVar1 = puVar3 + 2;
    puVar3 = (uint *)*puVar1;
  } while ((uint *)*puVar1 != (uint *)0x0);
  puVar3 = param_1;
  if (_DAT_3ffc06fc != (uint *)0x0) {
    *(uint **)(_DAT_3ffc0700 + 8) = param_1;
    memw();
    FUN_4018ceb0();
    do {
      iVar2 = FUN_4018cea0();
    } while (iVar2 != 0);
    iVar2 = FUN_4018ce14();
    if ((iVar2 != 0x3ff00000) || (iVar2 = FUN_4018b794(), iVar2 == param_2)) goto LAB_4018c751;
    param_1 = *(uint **)(iVar2 + 8);
    puVar3 = _DAT_3ffc06fc;
  }
  _DAT_3ffc06fc = puVar3;
  memw();
  FUN_4018ce24(param_1);
LAB_4018c751:
  _DAT_3ffc0700 = param_2;
  memw();
  return;
}

