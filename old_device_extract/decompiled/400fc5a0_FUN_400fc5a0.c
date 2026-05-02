// Function : FUN_400fc5a0
// Address  : 0x400fc5a0
// Size     : 40 bytes


undefined4 FUN_400fc5a0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)&SUB_4005cfec)(0xffffffff,param_1,1);
  uVar1 = (*(code *)&SUB_4005cfec)(uVar1,param_1 + 8,0x10);
  uVar1 = (*(code *)&SUB_4005cfec)(uVar1,param_1 + 3,1);
  return uVar1;
}

