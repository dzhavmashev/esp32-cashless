// Function : FUN_4011b1c4
// Address  : 0x4011b1c4
// Size     : 52 bytes


void FUN_4011b1c4(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 auStack_24 [9];
  
  uVar2 = FUN_40184ef4(param_1);
  if (((uVar2 & 1) != 0) &&
     (iVar3 = FUN_400f9524("ex_lock",1,auStack_24), uVar1 = auStack_24[0], iVar3 == 0)) {
    uVar4 = FUN_40184efc(param_1);
    FUN_400f953c(uVar1,uVar4);
    FUN_400f9738(auStack_24[0]);
    FUN_400f9a40(auStack_24[0]);
  }
  return;
}

