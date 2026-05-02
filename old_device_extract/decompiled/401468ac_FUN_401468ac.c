// Function : FUN_401468ac
// Address  : 0x401468ac
// Size     : 363 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401468ac(void)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  
  iVar1 = FUN_4014605c();
  if (iVar1 == 0) {
    puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x16c))(0x18);
    if (puVar2 == (undefined1 *)0x0) {
      FUN_401460a4();
      FUN_40147fe4(6,2,1,"memory!");
      return 0x101;
    }
    if (DAT_3ffc7918 != '\0') {
      (**(code **)(_DAT_3ffc1a34 + 0xb0))();
      FUN_401460a4();
      return 0x3014;
    }
    DAT_3ffc7918 = 1;
    memw();
    memw();
    FUN_401460a4();
    *puVar2 = 2;
    puVar2[8] = 0;
    memw();
    *(undefined4 *)(puVar2 + 4) = 0x4014f488;
    memw();
    iVar1 = FUN_40150444(puVar2);
    if (iVar1 == 0x3001) {
      iVar1 = 0x3001;
    }
    else if (iVar1 == 0x3002) {
      iVar1 = 0;
    }
    else {
      uVar3 = 0;
      do {
        puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x16c))(0x18);
        if (puVar2 == (undefined1 *)0x0) {
          pcVar7 = "memory!";
          uVar6 = 0x40;
          uVar5 = 6;
          goto LAB_401469f9;
        }
        *puVar2 = 2;
        puVar2[8] = 1;
        memw();
        *(undefined4 *)(puVar2 + 4) = 0x4014f488;
        memw();
        iVar1 = FUN_40150444();
        if (iVar1 == 0) goto LAB_401469c6;
        uVar3 = uVar3 + 1;
        pcVar4 = *(code **)(_DAT_3ffc1a34 + 0x9c);
        memw();
        (**(code **)(_DAT_3ffc1a34 + 0xa0))(10);
        (*pcVar4)();
        if (uVar3 == (uVar3 / 500) * 500) {
          memw();
          FUN_40147fe4(6,0x40,2,0x3f436386,uVar3,_DAT_3ff73cb8);
        }
      } while (uVar3 != 500);
      FUN_40147fe4(6,0x40,2,0x3f436376);
LAB_401469c6:
      puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x16c))(0x18);
      if (puVar2 == (undefined1 *)0x0) {
        pcVar7 = " ret=%d";
        uVar6 = 2;
        uVar5 = 1;
LAB_401469f9:
        FUN_40147fe4(uVar5,uVar6,1,pcVar7);
        iVar1 = 0x101;
      }
      else {
        *puVar2 = 2;
        puVar2[8] = 2;
        memw();
        *(undefined4 *)(puVar2 + 4) = 0x4014f488;
        memw();
        iVar1 = FUN_40150444();
      }
    }
    FUN_4014605c();
    DAT_3ffc7918 = '\0';
    memw();
    memw();
    FUN_401460a4();
  }
  return iVar1;
}

