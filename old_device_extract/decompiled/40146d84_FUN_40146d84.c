// Function : FUN_40146d84
// Address  : 0x40146d84
// Size     : 132 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40146d84(short *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_401460c8();
  uVar3 = 0x3001;
  if ((((iVar1 != 0) && (uVar3 = 0x3002, 1 < DAT_3ffc89d9)) &&
      (uVar3 = 0x102, param_1 != (short *)0x0)) && ((*param_1 == 0 || (param_2 != 0)))) {
    if ((_DAT_3ffc8864 != 0) && (iVar1 = (*_DAT_3ffc7a18)(), iVar1 == 0)) {
      return 0x3010;
    }
    puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
    uVar3 = 0x101;
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 7;
      memw();
      *(undefined **)(puVar2 + 4) = &DAT_4014f6d4;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      memw();
      *(short **)(puVar2 + 0xc) = param_1;
      *(int *)(puVar2 + 0x14) = param_2;
      memw();
      uVar3 = FUN_40150444();
    }
  }
  return uVar3;
}

