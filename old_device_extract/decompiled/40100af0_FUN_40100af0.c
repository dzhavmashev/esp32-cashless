// Function : FUN_40100af0
// Address  : 0x40100af0
// Size     : 40 bytes


undefined4 FUN_40100af0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = 0x103;
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + 8);
    uVar1 = *(undefined4 *)(iVar2 + 0x10);
    FUN_4010b270(uVar1,iVar3,iVar3 + 4,iVar3 + 8);
    FUN_4010b480(uVar1);
    FUN_40100adc(iVar2,1);
    uVar1 = 0;
  }
  return uVar1;
}

