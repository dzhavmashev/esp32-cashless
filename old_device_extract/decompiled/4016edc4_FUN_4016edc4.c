// Function : FUN_4016edc4
// Address  : 0x4016edc4
// Size     : 221 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016edc4(byte *param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_2 != '\0') {
    uVar1 = 0;
    do {
      uVar2 = (uVar1 & 0xff) >> 2;
      if (uVar2 == 1) {
        uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e134);
        _DAT_3ff4e134 =
             (0xff << 0x20 - ((uVar1 & 3) * -8 + 0x20) ^ 0xffffffffU) & uVar2 |
             (uint)*param_1 << 0x20 - ((uVar1 & 3) * -8 + 0x20);
        memw();
      }
      else if (uVar2 == 0) {
        uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e130);
        _DAT_3ff4e130 =
             (0xff << 0x20 - (0x20 - (uVar1 << 3 & 0x1f)) ^ 0xffffffffU) & uVar2 |
             (uint)*param_1 << 0x20 - (0x20 - (uVar1 << 3 & 0x1f));
        memw();
      }
      else {
        if (uVar2 == 2) {
          puVar3 = (uint *)0x3ff4e138;
        }
        else if (uVar2 == 3) {
          puVar3 = (uint *)0x3ff4e13c;
        }
        else {
          puVar3 = (uint *)&DAT_3ff4e140;
        }
        uVar2 = (*(code *)&SUB_40084594)(puVar3);
        memw();
        *puVar3 = (0xff << 0x20 - ((uVar1 & 3) * -8 + 0x20) ^ 0xffffffffU) & uVar2 |
                  (uint)*param_1 << 0x20 - ((uVar1 & 3) * -8 + 0x20);
      }
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 1;
    } while (uVar1 != (byte)(param_2 - 1) + 1);
  }
  return;
}

