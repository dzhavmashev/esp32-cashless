// Function : FUN_400d48b8
// Address  : 0x400d48b8
// Size     : 29 bytes


bool FUN_400d48b8(int param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = (*(code *)&LAB_40183c7b_1)(param_1);
  bVar1 = uVar2 == (param_2 & 0xff);
  if (bVar1) {
    *(undefined1 *)(param_1 + 0x1d) = 0;
  }
  return bVar1;
}

