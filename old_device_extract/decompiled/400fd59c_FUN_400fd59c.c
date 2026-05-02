// Function : FUN_400fd59c
// Address  : 0x400fd59c
// Size     : 453 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fd59c(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 auStack_65 [65];
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  memw();
  FUN_400fd52c();
  if (DAT_3ffc57c0 == '\0') goto LAB_400fd635;
  uVar4 = 0x400fd4a8;
  if (_DAT_3ffc57bc == 0) {
    uVar4 = 0;
  }
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[4] = uVar4;
  param_1[1] = 3;
  while( true ) {
    if (param_1[3] != 0) {
      memw();
      FUN_400fd498();
    }
    FUN_400fd498("ggered\r\n\r\n");
    if ((code *)param_1[4] != (code *)0x0) {
      (*(code *)param_1[4])(param_1[7]);
    }
    FUN_400fd498("ggered\r\n\r\n");
    iVar2 = (*(code *)&SUB_400842b0)();
    if (iVar2 == 0) break;
    FUN_400fd498("d (");
    FUN_400fd4c0(param_1[6]);
    FUN_400fd498("t at 0x");
    FUN_400fd448();
    (*(code *)&SUB_40092f10)(0,param_1[6]);
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (puStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
LAB_400fd635:
    if (param_1[2] != 0) {
      FUN_400fd498(&DAT_3f40dacc);
      FUN_400fd4ec(*param_1);
      FUN_400fd498(": Core ");
      FUN_400fd498(param_1[2]);
      FUN_400fd498("ic\'ed (");
    }
  }
  iVar2 = (*(code *)&SUB_40093dac)(0x3ffbdd3c);
  if (iVar2 == 0) {
    (*(code *)&SUB_4009386c)(0x3ffbdd3c,0,0,0);
    uVar3 = (*(code *)&SUB_4008d908)();
    (*(code *)&SUB_40093c14)(0x3ffbdd3c);
    uVar4 = (*(code *)&SUB_4000cff8)(uVar3 * 7000,(int)((ulonglong)uVar3 * 7000 >> 0x20),1000,0);
    (*(code *)&SUB_40093abc)(0x3ffbdd3c,0,uVar4,3);
    (*(code *)&SUB_40093c38)(0x3ffbdd3c);
    (*(code *)&SUB_40093d88)(0x3ffbdd3c);
  }
  FUN_400fd52c();
  if ((code *)param_1[5] != (code *)0x0) {
    (*(code *)param_1[5])(param_1[7]);
  }
  FUN_400fd498("ggered\r\n\r\n");
  FUN_400fd498("ng...\r\n");
  (*(code *)&SUB_4008178c)(auStack_65,0x41);
  FUN_400fd498(auStack_65);
  FUN_400fd498("ggered\r\n\r\n");
  FUN_400fd498("ggered\r\n\r\n");
  cVar1 = DAT_3ffc57b8;
  if (DAT_3ffc57b8 == '\0') goto LAB_400fd73c;
  FUN_400fd498("HA256: ");
  do {
    (*(code *)&SUB_40093c14)(0x3ffbdd3c);
    (*(code *)&SUB_40093c88)(0x3ffbdd3c);
    (*(code *)&SUB_40093d88)(0x3ffbdd3c);
    iVar2 = (*(code *)&SUB_400835a0)();
    if (iVar2 == 0) {
      param_1 = (undefined4 *)param_1[1];
      uVar4 = 5;
      if ((param_1 != (undefined4 *)0x1) && (uVar4 = 6, param_1 != (undefined4 *)0x2)) {
        uVar4 = 4;
      }
      (*(code *)&SUB_4008356c)(uVar4);
    }
    FUN_400fd498("dump!\r\n");
    FUN_400fdb2c();
LAB_400fd73c:
    FUN_400fd448();
    DAT_3ffc57b8 = 1;
    memw();
    memw();
    FUN_40121fa0(param_1);
    memw();
    memw();
    DAT_3ffc57b8 = cVar1;
    FUN_400fd52c();
  } while( true );
}

