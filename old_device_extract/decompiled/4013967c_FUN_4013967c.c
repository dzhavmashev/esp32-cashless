// Function : FUN_4013967c
// Address  : 0x4013967c
// Size     : 340 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4013967c(int param_1,int param_2,int param_3,undefined4 param_4,undefined1 *param_5,
                 undefined4 param_6)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 auStack_ce [16];
  undefined1 auStack_be [16];
  undefined1 auStack_ae [16];
  undefined1 auStack_9e [34];
  undefined1 auStack_7c [88];
  int iStack_24;
  undefined1 auStack_20 [32];
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  FUN_4013ce78(auStack_9e);
  FUN_401416d8(auStack_7c);
  iVar1 = FUN_401416c8(auStack_7c);
  if (iVar1 != 0) goto LAB_401396e9;
  iVar1 = FUN_401416b4(auStack_7c,param_5,param_6);
  if (iVar1 != 0) goto LAB_401396e9;
  iVar1 = FUN_401416b4(auStack_7c,param_1,8);
  if (iVar1 != 0) goto LAB_401396e9;
  iVar1 = FUN_401416a0(auStack_7c,auStack_ce);
  if (iVar1 != 0) goto LAB_401396e9;
  if (param_2 != 0x10) goto LAB_4013975d;
  puVar2 = auStack_be;
  iVar3 = 0x10;
  do {
    (*(code *)&SUB_4008b3d0)(puVar2,auStack_ce,iVar3);
LAB_401396e9:
    do {
      FUN_401416e8(auStack_7c);
      FUN_4013ae54(auStack_ce,0x10);
      if ((iVar1 == 0) && (iVar1 = FUN_4013cea0(auStack_9e,auStack_be,param_2 << 3), iVar1 == 0)) {
        iVar1 = FUN_4013cfac(auStack_9e,0,param_4,param_1,param_3,param_3);
      }
      param_1 = iVar1;
      FUN_4013ce8c(auStack_9e);
      param_5 = auStack_20;
      FUN_4013ae54(auStack_be,param_2);
      param_3 = iStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
LAB_4013975d:
      (*(code *)&SUB_4008b3d0)(auStack_be,auStack_ce,0x10);
      iVar1 = FUN_401416c8(auStack_7c);
    } while ((((iVar1 != 0) || (iVar1 = FUN_401416b4(auStack_7c,auStack_ce,0x10), iVar1 != 0)) ||
             (iVar1 = FUN_401416b4(auStack_7c,param_5,param_6), iVar1 != 0)) ||
            ((iVar1 = FUN_401416b4(auStack_7c,param_1,8), iVar1 != 0 ||
             (iVar1 = FUN_401416a0(auStack_7c,auStack_ce), iVar1 != 0))));
    iVar3 = 0x10;
    if (param_2 != 0x20) {
      iVar3 = param_2 + -0x10;
    }
    puVar2 = auStack_ae;
  } while( true );
}

