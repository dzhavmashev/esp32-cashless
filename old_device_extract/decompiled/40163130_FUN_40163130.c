// Function : FUN_40163130
// Address  : 0x40163130
// Size     : 260 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163130(void)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  
  bVar1 = false;
  uVar5 = 0;
  bVar3 = false;
  uVar4 = 0;
  do {
    while( true ) {
      iVar2 = FUN_401630f8();
      if (iVar2 == 0) {
        if (bVar1) {
          FUN_401882d0();
        }
        FUN_401622ec(uVar4,bVar3,uVar5);
        return;
      }
      FUN_40188374(iVar2,0);
      FUN_40162b5c(iVar2);
      puVar6 = *(uint **)(iVar2 + 0x2c);
      if ((*puVar6 & 8) != 0) {
        uVar7 = puVar6[4] >> 0x13 & 1;
        if (((uVar7 == 0) && (*(char *)((int)puVar6 + 0x13) == '\x01')) &&
           (uVar4 = 1, DAT_3ffc1a44 != '\0')) {
          bVar3 = (puVar6[4] & 0xf00) != 0;
        }
        if (_DAT_3ffc7c08 != (code *)0x0) {
          (*_DAT_3ffc7c08)(uVar7,*(undefined4 *)(*(int *)(iVar2 + 4) + 4),iVar2 + 0x16,
                           *(char *)((int)puVar6 + 0x13) == '\x01');
        }
      }
      uVar7 = **(uint **)(iVar2 + 0x2c);
      if ((uVar7 & 0x2000) == 0) break;
      uVar5 = 1;
      if ((uVar7 & 0x40008) == 8) {
        FUN_40164ea0(*(undefined4 *)(iVar2 + 0x24),iVar2);
        uVar5 = 1;
      }
LAB_40163208:
      if (*(char *)(iVar2 + 0x1a) == '\x01') {
        bVar1 = true;
      }
      FUN_4018a7b8(iVar2);
    }
    if ((uVar7 & 0x800000) == 0) {
      if (*(char *)(iVar2 + 0x1a) != '\x05') goto LAB_40163208;
      FUN_40147fe4(6,0x40,3,0x3f435ae7);
    }
    else {
      puVar6 = *(uint **)(iVar2 + 8);
      *(short *)(iVar2 + 0x16) = *(short *)(iVar2 + 0x16) + -4;
      memw();
      memw();
      memw();
      memw();
      *puVar6 = *puVar6 & 0xff000fff | ((*puVar6 >> 0xc & 0xfff) - 4 & 0xfff) << 0xc;
      memw();
    }
  } while( true );
}

