// Function : FUN_40171228
// Address  : 0x40171228
// Size     : 84 bytes


undefined4 FUN_40171228(code *param_1,undefined4 param_2)

{
  uint unaff_retaddr;
  int iVar1;
  int iVar2;
  undefined1 auStack_70 [56];
  undefined1 auStack_38 [56];
  
  (*(code *)&SUB_40092e4c)();
  FUN_40170bac(auStack_70,&stack0x00000000,unaff_retaddr & 0x3fffffff | 0x40000000);
  while (((iVar1 = FUN_40170bfc(auStack_70,auStack_38), iVar1 == 0 || (iVar1 == 5)) &&
         (iVar2 = (*param_1)(auStack_70,param_2), iVar2 == 0))) {
    if (iVar1 == 5) {
      return 5;
    }
    FUN_40170ddc(auStack_70,auStack_38);
  }
  return 3;
}

