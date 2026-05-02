// Function : FUN_4010cf7c
// Address  : 0x4010cf7c
// Size     : 94 bytes


uint FUN_4010cf7c(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int extraout_a3;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  param_1 = param_1 & 0xffff;
  iVar4 = param_2;
  if (param_3 == 0) {
    (*(code *)&SUB_40094c54)(" LISTEN",0x926,"pcblist","lid pcb");
    iVar4 = extraout_a3;
  }
  if (*(char *)(param_3 + 0x14) == '\x06') {
    uVar1 = FUN_4011a800(param_3,iVar4);
    if (uVar1 == 0) {
      return param_1;
    }
    uVar2 = 0x28;
    if (*(char *)(param_3 + 0x14) == '\x06') {
      uVar2 = 0x3c;
    }
  }
  else {
    if (param_2 == 0) {
      return param_1;
    }
    uVar1 = (uint)*(ushort *)(param_2 + 0xe0);
    if (uVar1 == 0) {
      return param_1;
    }
    uVar2 = 0x28;
  }
  uVar3 = 0;
  if (uVar2 < uVar1) {
    uVar3 = uVar1 - uVar2 & 0xffff;
  }
  return (uVar3 < param_1) * uVar3 + (uVar3 >= param_1) * param_1;
}

