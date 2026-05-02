// Function : FUN_40126f6c
// Address  : 0x40126f6c
// Size     : 203 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40126f6c(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_224 [512];
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  memw();
  uVar1 = FUN_40128c08(*(undefined4 *)(*param_1 + 0x50));
  iVar6 = uVar1 + 7;
  if ((int)(uVar1 + 7) < 0) {
    iVar6 = uVar1 + 0xe;
  }
  uVar5 = iVar6 >> 3;
  uVar2 = uVar1;
  if (uVar5 < 0x201) goto LAB_40126fb8;
LAB_40126f9a:
  param_1 = (int *)0x0;
  do {
    uVar1 = uStack_24;
    uVar5 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return;
    }
    uVar2 = (*(code *)&SUB_40082ec4)();
LAB_40126fb8:
    uVar2 = uVar2 & 0x80000007;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
    }
    iVar6 = 0x66;
    while( true ) {
      iVar6 = iVar6 + -1;
      if (iVar6 == 0) goto LAB_40126f9a;
      memw();
      iVar3 = FUN_40102858(auStack_224,uVar5);
      if (iVar3 < 0) goto LAB_40126f9a;
      if ((uVar1 & 7) != 0) {
        FUN_40185770(auStack_224,uVar5,8 - uVar2);
      }
      piVar4 = (int *)FUN_40128a30(auStack_224,uVar5);
      if (piVar4 == (int *)0x0) goto LAB_40126f9a;
      iVar3 = FUN_40128c14();
      if (((iVar3 == 0) && (iVar3 = FUN_40128c2c(piVar4), iVar3 == 0)) &&
         (iVar3 = FUN_40128bf4(piVar4,*(undefined4 *)(*param_1 + 0x50)), iVar3 < 0)) break;
      FUN_40128a7c(piVar4,0);
    }
    FUN_40102884(auStack_224,uVar5);
    param_1 = piVar4;
  } while( true );
}

