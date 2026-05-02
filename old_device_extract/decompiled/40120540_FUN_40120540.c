// Function : FUN_40120540
// Address  : 0x40120540
// Size     : 275 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40120540(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char *pcVar9;
  
  uVar5 = *(undefined4 *)(_DAT_3ffc6d20 + 0x28);
  uVar7 = *(undefined4 *)(_DAT_3ffc6d20 + 0x20);
  pcVar4 = *(code **)(_DAT_3ffc6d20 + 0x24);
  pcVar6 = *(code **)(_DAT_3ffc6d20 + 0x1c);
  uVar2 = *(uint *)(_DAT_3ffc6d20 + 0x6c);
  memw();
  (*(code *)&SUB_40091834)((100 < uVar2) * uVar2 + (uint)(100 >= uVar2) * 100);
  (**(code **)(_DAT_3ffc6d20 + 4))(*(undefined4 *)(_DAT_3ffc6d20 + 0x34));
  FUN_4012121c(*(undefined4 *)(_DAT_3ffc6d20 + 0x34));
  iVar1 = _DAT_3ffc6d20;
  uVar8 = *(undefined4 *)(*(int *)(_DAT_3ffc6d20 + 0x54) + 0xc);
  *(undefined4 *)(_DAT_3ffc6d20 + 0x34) = 0;
  memw();
  (*(code *)&SUB_40094d80)(uVar8);
  (*(code *)&SUB_40094d80)(*(undefined4 *)(iVar1 + 0x54));
  uVar8 = *(undefined4 *)(*(int *)(iVar1 + 0x58) + 0xc);
  *(undefined4 *)(iVar1 + 0x54) = 0;
  memw();
  (*(code *)&SUB_40094d80)(uVar8);
  (*(code *)&SUB_40094d80)(*(undefined4 *)(iVar1 + 0x58));
  *(undefined4 *)(iVar1 + 0x58) = 0;
  memw();
  FUN_401467e4(1);
  if (param_1 != 0) {
    iVar1 = (*(code *)&SUB_40090010)(_DAT_3ffc6d24,0xffffffff);
    puVar3 = (undefined4 *)&DAT_3ffc6d20;
    if (iVar1 == 1) goto LAB_401205e1;
    uVar8 = 0x1f5;
    pcVar9 = "t loop\n";
    while( true ) {
      (*(code *)&SUB_40094c54)("ing/src/manager.c",uVar8,"DEINIT\n",pcVar9);
LAB_401205e1:
      uVar8 = _DAT_3ffc6d24;
      puVar3 = (undefined4 *)*puVar3;
      puVar3[0xb] = 0;
      memw();
      iVar1 = (*(code *)&SUB_4008fab8)(uVar8,0,0,0);
      if (iVar1 == 1) break;
      uVar8 = 0x1f7;
      pcVar9 = "release";
    }
    if (pcVar6 != (code *)0x0) {
      (*pcVar6)(uVar7,5,0);
    }
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(uVar5,5,0);
    }
    iVar1 = FUN_4018cf2c(_DAT_3ffbf670,5,0,0,0xffffffff);
    if (iVar1 != 0) {
      uVar5 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"nager.c"," found\n",uVar5,"nager.c");
    }
    (*(code *)&SUB_40091738)(0);
  }
  return;
}

