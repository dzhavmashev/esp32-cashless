// Function : FUN_40120654
// Address  : 0x40120654
// Size     : 557 bytes


/* WARNING: Instruction at (ram,0x4012080e) overlaps instruction at (ram,0x4012080c)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_40120654(uint param_1)

{
  byte bVar1;
  int *piVar2;
  int unaff_retaddr;
  int iVar3;
  uint uVar4;
  int *extraout_a4;
  int *piVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined4 in_f15;
  
  puVar6 = (undefined1 *)0x1;
  if (param_1 != 0) goto LAB_401206c1;
  do {
    if (_DAT_3ffc6d20 == 0) goto LAB_401206dd;
    if (*(int *)(_DAT_3ffc6d20 + 0x2c) != 1) {
      if (*(int *)(_DAT_3ffc6d20 + 0x2c) != 6) goto LAB_401206dd;
      goto LAB_40120672;
    }
    iVar3 = (*(code *)&SUB_4008fab8)(_DAT_3ffc6d24,0,0);
    puVar7 = (undefined4 *)0x1;
    if (iVar3 != 1) {
      pcVar10 = "release";
      uVar9 = 0x226;
      puVar6 = &DAT_3ffc6d24;
      goto LAB_40120694;
    }
    (*(code *)&SUB_40091834)(100);
    iVar3 = (*(code *)&SUB_40090010)(_DAT_3ffc6d24,0xffffffff);
    puVar6 = &DAT_3ffc6d24;
  } while (iVar3 == 1);
  uVar9 = 0x228;
  pcVar10 = "t loop\n";
LAB_40120694:
  do {
    (*(code *)&SUB_40094c54)("ing/src/manager.c",uVar9,"nternal",pcVar10);
    do {
      (*(code *)&SUB_40091834)(100);
      iVar3 = (*(code *)&SUB_40090010)(*puVar7,0xffffffff);
      if (iVar3 != 1) {
        uVar9 = 0x21f;
        pcVar10 = "t loop\n";
        goto LAB_40120694;
      }
LAB_401206c1:
      if (_DAT_3ffc6d20 == 0) goto LAB_401206dd;
      puVar8 = (undefined1 *)0x0;
      if (*(int *)(_DAT_3ffc6d20 + 0x2c) == 1) {
        puVar8 = puVar6;
      }
      if (((uint)puVar8 & 0xff) == 0) {
        puVar8 = (undefined1 *)0x0;
        if (*(int *)(_DAT_3ffc6d20 + 0x2c) == 6) {
          puVar8 = puVar6;
        }
        if (puVar8 == (undefined1 *)0x0) goto LAB_401206dd;
      }
      iVar3 = (*(code *)&SUB_4008fab8)(_DAT_3ffc6d24,0,0);
      puVar7 = (undefined4 *)&DAT_3ffc6d24;
    } while (iVar3 == 1);
    uVar9 = 0x21d;
    pcVar10 = "release";
  } while( true );
LAB_40120672:
  param_1 = 0;
  goto LAB_40120820;
LAB_401206dd:
  piVar5 = (int *)&DAT_3ffc6d20;
  if ((_DAT_3ffc6d20 == 0) || (*(int *)(_DAT_3ffc6d20 + 0x2c) == 0)) goto LAB_40120672;
  if (*(int *)(_DAT_3ffc6d20 + 0x44) != 0) {
    (*(code *)&SUB_40085a10)();
    FUN_4011f8dc(*(undefined4 *)(_DAT_3ffc6d20 + 0x44));
    *(undefined4 *)(_DAT_3ffc6d20 + 0x44) = 0;
  }
  if (*(int *)(_DAT_3ffc6d20 + 0x48) != 0) {
    memw();
    (*(code *)&SUB_40085a10)();
    FUN_4011f8dc(*(undefined4 *)(_DAT_3ffc6d20 + 0x48));
    *(undefined4 *)(_DAT_3ffc6d20 + 0x48) = 0;
  }
  iVar3 = _DAT_3ffc6d20;
  piVar2 = (int *)(_DAT_3ffc6d20 + 0x3c);
  *(undefined4 *)(_DAT_3ffc6d20 + 0x2c) = 6;
  if (*piVar2 != 0) {
    memw();
    (*(code *)&SUB_40094d80)();
    *(undefined4 *)(iVar3 + 0x3c) = 0;
  }
  puVar7 = (undefined4 *)(iVar3 + 0x90);
  do {
    memw();
    (*(code *)&SUB_40094d80)(*puVar7);
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  } while (puVar7 != (undefined4 *)(iVar3 + 200));
  *(undefined1 *)(iVar3 + 0x70) = 0;
  memw();
  *(undefined4 *)(iVar3 + 200) = 0;
  memw();
  FUN_4018cf0c(_DAT_3ffbdea0,0xffffffff,0x401200e8);
  FUN_4018cf0c(_DAT_3ffbde84,0,0x401200e8);
  if (param_1 != 0) {
    iVar3 = (*(code *)&SUB_4008fab8)(_DAT_3ffc6d24,0,0);
    puVar7 = (undefined4 *)&DAT_3ffc6d24;
    puVar6 = &DAT_3ffbdea0;
    if (iVar3 == 1) {
      FUN_40120540(0);
      iVar3 = (*(code *)&SUB_40090010)(_DAT_3ffc6d24,0xffffffff);
      puVar7 = (undefined4 *)&DAT_3ffc6d24;
      puVar6 = &DAT_3ffbdea0;
      uVar9 = 0;
      if (iVar3 == 1) goto LAB_4012081c;
      uVar9 = 0x261;
      pcVar10 = "t loop\n";
    }
    else {
      uVar9 = 0x25f;
      pcVar10 = "release";
    }
    goto LAB_40120694;
  }
  memw();
  param_1 = 1;
  iVar3 = (*(code *)&SUB_4009092c)(0x40120538,"OV_END\n",0x1000,1,0,0,0x7fffffff);
  if (iVar3 == 1) goto LAB_40120820;
  uVar4 = (*(code *)&SUB_40094b80)();
  FUN_4012113c(1,"nager.c","op_task",uVar4,"nager.c");
  (*(code *)&SUB_40094bc8)();
  cust0();
  uVar9 = 0xfffc06ff;
  if ((uVar4 & 0x80000000) == 0) {
    bVar1 = *(byte *)(unaff_retaddr + 0x56);
    uVar9 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"nager.c"," pdTRUE",uVar9,"nager.c");
    return (uint)bVar1;
  }
  uRam80000303 = in_f15;
  param_1 = func_0x40127458(0xb,0x80000303);
  flix();
  piVar5 = extraout_a4;
LAB_4012081c:
  *(undefined4 *)(*piVar5 + 0x2c) = uVar9;
LAB_40120820:
  memw();
  return param_1;
}

