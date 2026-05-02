// Function : FUN_4011e144
// Address  : 0x4011e144
// Size     : 85 bytes


undefined4 FUN_4011e144(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0x102;
  if (param_1 != 0) {
    piVar2 = (int *)0x3f413a50;
    for (iVar1 = 0; iVar1 != 0x736e6f69; iVar1 = iVar1 + 1) {
      if ((*piVar2 <= param_1) && (param_1 < *piVar2 + piVar2[1])) {
        uVar3 = FUN_4011e078(&UNK_3f413d98 + (&DAT_3f413a58)[iVar1 * 4] * 0x14,param_1,param_2);
        return uVar3;
      }
      piVar2 = piVar2 + 4;
    }
    uVar3 = 0x105;
  }
  return uVar3;
}

