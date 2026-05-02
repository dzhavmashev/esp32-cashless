// Function : FUN_40134c00
// Address  : 0x40134c00
// Size     : 251 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40134c00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 ****ppppuVar5;
  undefined4 ***pppuStack_cc;
  undefined1 auStack_c8 [12];
  undefined1 auStack_bc [13];
  undefined1 auStack_af [139];
  undefined4 ***local_24 [9];
  
  ppppuVar5 = local_24;
  memw();
  memw();
  local_24[0] = _DAT_3ffc5708;
  memw();
  FUN_40186008(auStack_c8);
  FUN_40186008(auStack_bc);
  memw();
  iVar1 = FUN_40134a88(param_1,auStack_c8,auStack_bc,param_1 + 0x7c,param_3,param_4,param_2,param_7,
                       param_8);
  if (iVar1 == 0) {
    (*(code *)&SUB_4008b530)(auStack_af,0,0x8b);
    memw();
    pppuStack_cc = ppppuVar5;
    iVar1 = FUN_401312c0(&pppuStack_cc,auStack_af,auStack_bc);
    if ((-1 < iVar1) && (iVar2 = FUN_401312c0(&pppuStack_cc,auStack_af,auStack_c8), -1 < iVar2)) {
      iVar3 = FUN_40131188(&pppuStack_cc,auStack_af,iVar1 + iVar2);
      if ((-1 < iVar3) && (iVar4 = FUN_40185bfc(&pppuStack_cc,auStack_af,0x30), -1 < iVar4)) {
        iVar4 = iVar4 + iVar3 + iVar1 + iVar2;
        (*(code *)&SUB_4008b3d0)(param_5,pppuStack_cc,iVar4);
        *param_6 = iVar4;
      }
    }
  }
  while( true ) {
    memw();
    FUN_40131548(auStack_c8);
    FUN_40131548(auStack_bc);
    memw();
    ppppuVar5 = (undefined4 ****)*ppppuVar5;
    memw();
    if (ppppuVar5 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
  }
  return;
}

