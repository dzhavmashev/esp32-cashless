// Function : FUN_400fdd44
// Address  : 0x400fdd44
// Size     : 47 bytes


void FUN_400fdd44(int param_1,int param_2)

{
  uint uVar1;
  char *pcVar2;
  
  uVar1 = *(uint *)(param_1 + 0x50);
  pcVar2 = "on lost";
  if (uVar1 < 0x28) {
    pcVar2 = (&PTR_s_on_CPU0_3f40e18c)[uVar1];
  }
  *(char **)(param_2 + 8) = pcVar2;
  *(undefined ***)(param_2 + 0xc) = &PTR_s_BEG_3f40dec4;
  if (uVar1 == 0) {
    *(undefined **)(param_2 + 0x10) = &DAT_400fdb9c;
  }
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 4);
  memw();
  return;
}

