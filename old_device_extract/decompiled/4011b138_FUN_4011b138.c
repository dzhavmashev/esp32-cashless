// Function : FUN_4011b138
// Address  : 0x4011b138
// Size     : 75 bytes


bool FUN_4011b138(int param_1)

{
  undefined4 uVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 auStack_24 [9];
  
  iVar6 = *(int *)(param_1 + 200);
  uVar3 = FUN_40184e40(param_1);
  uVar4 = FUN_40184ef4();
  if (((uVar4 & 1) == 0) ||
     (iVar5 = FUN_400f9524("ex_lock",0,auStack_24), uVar1 = auStack_24[0], iVar5 != 0)) {
    bVar2 = false;
  }
  else {
    uVar3 = FUN_40184efc(uVar3);
    iVar6 = FUN_400f994c(uVar1,uVar3,iVar6 + 0x3c);
    bVar2 = iVar6 == 0;
    FUN_400f9a40(auStack_24[0]);
  }
  return bVar2;
}

