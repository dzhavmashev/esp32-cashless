// Function : FUN_40123800
// Address  : 0x40123800
// Size     : 23 bytes


undefined4 FUN_40123800(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_40123818();
  return *(undefined4 *)(iVar1 + param_1 * 0x10 + param_2 * 4 + 8);
}

