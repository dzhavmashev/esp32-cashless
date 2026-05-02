// Function : FUN_400fc574
// Address  : 0x400fc574
// Size     : 44 bytes


undefined4 FUN_400fc574(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)&SUB_4005cfec)(0xffffffff,param_1,4);
  uVar1 = (*(code *)&SUB_4005cfec)(uVar1,param_1 + 8,0x10);
  uVar1 = (*(code *)&SUB_4005cfec)(uVar1,param_1 + 0x18,8);
  return uVar1;
}

