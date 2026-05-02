// Function : FUN_4011b184
// Address  : 0x4011b184
// Size     : 62 bytes


void FUN_4011b184(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 auStack_24 [9];
  
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 200) + 0x3c);
  uVar2 = FUN_40184e40(param_1);
  uVar3 = FUN_40184ef4();
  if (((uVar3 & 1) != 0) &&
     (iVar4 = FUN_400f9524("ex_lock",1,auStack_24), uVar1 = auStack_24[0], iVar4 == 0)) {
    uVar2 = FUN_40184efc(uVar2);
    FUN_400f96f0(uVar1,uVar2,uVar5);
    FUN_400f9738(auStack_24[0]);
    FUN_400f9a40(auStack_24[0]);
  }
  return;
}

