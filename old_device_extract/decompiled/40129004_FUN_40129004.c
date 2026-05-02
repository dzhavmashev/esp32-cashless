// Function : FUN_40129004
// Address  : 0x40129004
// Size     : 119 bytes


byte FUN_40129004(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  FUN_40186008(auStack_38);
  FUN_40186008(auStack_2c);
  iVar1 = FUN_40131700(auStack_2c,2);
  if (iVar1 == 0) {
    iVar1 = FUN_4013d3d8(auStack_38,param_2 + 0xc,auStack_2c,param_1 + 4,0);
    iVar2 = 0;
    bVar4 = 0;
    if (iVar1 == 0) {
      iVar2 = FUN_40128f18(param_1,param_2);
      bVar4 = 0;
      if (iVar2 != 0) {
        iVar3 = FUN_401860ec(iVar2,auStack_38);
        bVar4 = 1;
        if (iVar3 != 0) {
          bVar4 = 0;
        }
      }
    }
  }
  else {
    bVar4 = 0;
    iVar2 = 0;
  }
  FUN_40131548(auStack_38);
  FUN_40131548(auStack_2c);
  FUN_40131548(iVar2);
  (*(code *)&SUB_40094d80)(iVar2);
  return bVar4 & iVar1 == 0;
}

