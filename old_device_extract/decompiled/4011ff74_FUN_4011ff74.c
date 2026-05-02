// Function : FUN_4011ff74
// Address  : 0x4011ff74
// Size     : 210 bytes


/* WARNING: Removing unreachable block (ram,0x40120012) */
/* WARNING: Removing unreachable block (ram,0x40120017) */
/* WARNING: Removing unreachable block (ram,0x4012002d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4011ff74(uint param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  if ((_DAT_3ffc09bc != 0) || ((param_1 & _DAT_3ffc1bc0) == 0)) {
    uVar3 = 0x103;
LAB_4011ffb0:
    memw();
    return uVar3;
  }
  puVar4 = (uint *)&DAT_3ffc1bc0;
  bVar1 = true;
  uVar5 = 0;
  iVar6 = 0;
  do {
    uVar7 = *puVar4;
    *puVar4 = (param_1 ^ 0xffffffff) & uVar7;
    if ((uVar7 != 0) && (uVar7 == (param_1 & uVar7))) {
      if (bVar1) {
        uVar5 = puVar4[1];
      }
      if (iVar6 == 6) goto LAB_4011ffe8;
      uVar7 = puVar4[3];
      if (((uVar7 == 0) || (uVar7 != (param_1 & uVar7))) || (puVar4[2] != puVar4[4])) {
        iVar2 = FUN_4011ff58(uVar5);
        if (iVar2 == 0) goto LAB_40120004;
        uVar3 = 0x55c;
        goto LAB_4011ffdf;
      }
      bVar1 = false;
    }
    while( true ) {
      iVar6 = iVar6 + 1;
      puVar4 = puVar4 + 3;
      if (iVar6 != 7) break;
      if ((param_1 != 3) || (iVar2 = FUN_4011ff58(), iVar2 == 0)) {
        uVar3 = 0;
        goto LAB_4011ffb0;
      }
      uVar3 = 0x572;
LAB_4011ffdf:
      while( true ) {
        (*(code *)&SUB_4008effc)(iVar2,"em_end)",uVar3,"32/bt.c","k_close");
LAB_4011ffe8:
        iVar2 = FUN_4011ff58(uVar5,_DAT_3ffc1c10);
        if (iVar2 == 0) break;
        uVar3 = 0x562;
      }
LAB_40120004:
      bVar1 = true;
    }
  } while( true );
}

