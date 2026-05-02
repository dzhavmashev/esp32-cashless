// Function : FUN_40115008
// Address  : 0x40115008
// Size     : 81 bytes


void FUN_40115008(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint in_t0;
  
  uVar2 = *(uint *)(param_1 + 200);
  if (uVar2 != 0) {
    uVar1 = (uint)*(byte *)(uVar2 + 5);
    if (5 < uVar1) goto LAB_40115035;
    if (uVar1 < 3) {
      if (uVar1 == 0) {
        return;
      }
      do {
        if (uVar1 < 0xd) {
          *(undefined1 *)(uVar2 + 6) = 0;
          memw();
          memw();
          FUN_40114954(param_1);
          return;
        }
        uVar1 = in_t0;
        param_1 = (*(code *)&SUB_40094c54)("ONS_LEN",0x450,"->state","hcp set");
        uVar2 = uVar1;
        in_t0 = uVar1;
LAB_40115035:
      } while (uVar1 != 10);
    }
    *(undefined1 *)(uVar2 + 6) = 0;
    memw();
    memw();
    FUN_4011463c();
  }
  return;
}

