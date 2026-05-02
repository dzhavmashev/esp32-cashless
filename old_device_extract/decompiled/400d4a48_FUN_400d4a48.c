// Function : FUN_400d4a48
// Address  : 0x400d4a48
// Size     : 85 bytes


undefined4 FUN_400d4a48(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  
  uVar4 = *(undefined4 *)(param_1 + 4);
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  puVar2 = (uint *)FUN_400d48f8(uVar4,uVar1);
  if (puVar2 != (uint *)0x0) {
    bVar5 = (byte)puVar2[2] & 0x7f;
    if (bVar5 == 8) {
      if ((puVar2[1] == 0) && (-1 < (int)*puVar2)) goto LAB_400d4a75;
    }
    else if ((bVar5 == 10) && ((uint)(*puVar2 + 0x80000000 < *puVar2) + puVar2[1] == 0)) {
LAB_400d4a75:
      iVar3 = FUN_400d48f8(uVar4,uVar1);
      if (iVar3 == 0) {
        return 0;
      }
      uVar1 = FUN_400d4348();
      return uVar1;
    }
  }
  return *param_2;
}

