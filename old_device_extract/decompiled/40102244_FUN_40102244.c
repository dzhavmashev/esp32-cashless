// Function : FUN_40102244
// Address  : 0x40102244
// Size     : 107 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40102244(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_56 [16];
  undefined1 auStack_46 [34];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  FUN_4013ce78(auStack_46);
  iVar1 = FUN_4013cea0(auStack_46,param_1,0x80);
  if (-1 < iVar1) goto LAB_40102289;
  while( true ) {
    FUN_4013ce8c(auStack_46);
    param_3 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
LAB_40102289:
    (*(code *)&SUB_4008b3d0)(auStack_56,param_2,0x10);
    iVar1 = FUN_4013cfac(auStack_46,1,param_4,auStack_56,param_3,param_3);
  }
  return iVar1;
}

