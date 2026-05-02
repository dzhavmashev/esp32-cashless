// Function : FUN_40147a54
// Address  : 0x40147a54
// Size     : 304 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40147a54(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 uVar2;
  
  if (param_1 == 1) {
LAB_40147a90:
    uVar7 = FUN_40147918();
    if (param_1 != 1) goto LAB_40147aad;
    if (*(code **)(_DAT_3ffc87ec + 8) != (code *)0x0) {
      (**(code **)(_DAT_3ffc87ec + 8))();
    }
  }
  else {
    if (param_1 == 0) {
      FUN_40147fe4(1,1,3,0x3f434d25);
      FUN_401479d8();
      if (*(code **)(_DAT_3ffc87ec + 8) != (code *)0x0) {
        (**(code **)(_DAT_3ffc87ec + 8))();
      }
      return 0;
    }
    if (param_1 != 2) {
      if (param_1 != 3) {
        return 0x102;
      }
      goto LAB_40147a90;
    }
LAB_40147aad:
    if (*(code **)(_DAT_3ffc87ec + 4) == (code *)0x0) {
      return 0x102;
    }
    uVar7 = (**(code **)(_DAT_3ffc87ec + 4))();
    if (param_1 == 2) {
      FUN_401479d8();
      uVar8 = 0x3f434ccc;
      memw();
      uVar1 = DAT_3ffc89f8;
      uVar2 = DAT_3ffc89f9;
      uVar3 = DAT_3ffc89fa;
      uVar4 = DAT_3ffc89fb;
      uVar5 = DAT_3ffc89fc;
      uVar6 = DAT_3ffc89fd;
      goto LAB_40147b22;
    }
    if (param_1 != 1) {
      if (param_1 != 3) {
        return uVar7;
      }
      memw();
      FUN_40147fe4(1,1,3,0x3f434c78,DAT_3ffc89fe,DAT_3ffc89ff,DAT_3ffc8a00,DAT_3ffc8a01,DAT_3ffc8a02
                   ,DAT_3ffc8a03,DAT_3ffc89f8,DAT_3ffc89f9,DAT_3ffc89fa,DAT_3ffc89fb,DAT_3ffc89fc,
                   DAT_3ffc89fd);
      return uVar7;
    }
  }
  uVar8 = 0x3f434cfa;
  uVar1 = DAT_3ffc89fe;
  uVar2 = DAT_3ffc89ff;
  uVar3 = DAT_3ffc8a00;
  uVar4 = DAT_3ffc8a01;
  uVar5 = DAT_3ffc8a02;
  uVar6 = DAT_3ffc8a03;
LAB_40147b22:
  memw();
  FUN_40147fe4(1,1,3,uVar8,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6);
  return uVar7;
}

