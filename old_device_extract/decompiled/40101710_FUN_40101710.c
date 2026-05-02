// Function : FUN_40101710
// Address  : 0x40101710
// Size     : 42 bytes


undefined4 FUN_40101710(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 0x102;
  }
  else {
    (*(code *)&SUB_4008b3d0)(param_2,*(undefined4 *)(param_1 + 0xc),0xc);
    uVar1 = 0;
  }
  return uVar1;
}

